#ifndef RAW_SENT_H_
#define RAW_SENT_H_

#include <iostream>
#include <vector>
#include <string>

namespace cnn { class Dict; }

namespace parser {

// a sentence can be viewed in 4 different ways:
//   raw tokens, UNKed, lowercased, and POS tags
struct RawSent {
  size_t size() const { return raw.size(); }
  std::vector<int> pos, raw;
};

// base class for transition based parse oracles
struct RawOracle {
  virtual ~RawOracle();
  RawOracle(cnn::Dict* dict, cnn::Dict* adict, cnn::Dict* pdict) : d(dict), ad(adict), pd(pdict), sents() {}
  unsigned size() const { return sents.size(); }
  cnn::Dict* d;  // dictionary of terminal symbols
  cnn::Dict* ad; // dictionary of action types
  cnn::Dict* pd; // dictionary of POS tags (preterminal symbols)
  std::vector<Sentence> sents;
 protected:
  static void ReadSentenceView(const std::string& line, cnn::Dict* dict, std::vector<int>* sent);
};

// oracle that predicts nonterminal symbols with a NT(X) action
// the action NT(X) effectively introduces an "(X" on the stack
// # (S (NP ...
// raw tokens
// tokens with OOVs replaced
class TopDownRawOracle : public RawOracle {
 public:
  TopDownRawOracle(cnn::Dict* termdict, cnn::Dict* adict, cnn::Dict* pdict, cnn::Dict* nontermdict) :
      RawOracle(termdict, adict, pdict), nd(nontermdict) {}
  // if is_training is true, then both the "raw" tokens and the mapped tokens
  // will be read, and both will be available. if false, then only the mapped
  // tokens will be available
  void load_oracle(const std::string& file, bool is_training);
  cnn::Dict* nd; // dictionary of nonterminal types
};
#endif
