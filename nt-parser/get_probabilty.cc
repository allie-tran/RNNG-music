#include <nt-parser/nt-parser-gen.cc>


int main(int argc, char** argv) {
    cnn::Initialize(argc, argv);
    cerr << "COMMAND LINE:"; 
    for (unsigned i = 0; i < static_cast<unsigned>(argc); ++i) cerr << ' ' << argv[i];
    cerr << endl;
    unsigned status_every_i_iterations = 100;

    po::variables_map conf;
    InitCommandLine(argc, argv, &conf);
    if (conf.count("clusters") == 0) {
        cerr << "Please specify vocabulary clustering with --clusters FILE when training generative model\n";
        return 1;
    }
   
//     LAYERS = conf["layers"].as<unsigned>();
//     INPUT_DIM = conf["input_dim"].as<unsigned>();
//     PRETRAINED_DIM = conf["pretrained_dim"].as<unsigned>();
//     HIDDEN_DIM = conf["hidden_dim"].as<unsigned>();
//     ACTION_DIM = conf["action_dim"].as<unsigned>();
//     LSTM_INPUT_DIM = conf["lstm_input_dim"].as<unsigned>();
   
//     ostringstream os;
//     os << "ntparse_gen"
//         << "_D" << DROPOUT
//         << '_' << LAYERS
//         << '_' << INPUT_DIM
//         << '_' << HIDDEN_DIM
//         << '_' << ACTION_DIM
//         << '_' << LSTM_INPUT_DIM
//         << "-pid" << getpid() << ".params";
//     const string fname = os.str();
//     cerr << "PARAMETER FILE: " << fname << endl;
//     bool softlinkCreated = false;

//     kSOS = termdict.Convert("<s>");
//     Model model;
//     cfsm = new ClassFactoredSoftmaxBuilder(HIDDEN_DIM, conf["clusters"].as<string>(), &termdict, &model);

//     // parser::TopDownOracleGen corpus(&termdict, &adict, &posdict, &ntermdict);
//     // parser::TopDownOracleGen dev_corpus(&termdict, &adict, &posdict, &ntermdict);
//     // parser::TopDownOracleGen2 test_corpus(&termdict, &adict, &posdict, &ntermdict);
//     // corpus.load_oracle(conf["training_data"].as<string>());

//     // freeze dictionaries so we don't accidentaly load OOVs
//     termdict.Freeze();
//     adict.Freeze();
//     ntermdict.Freeze();
//     posdict.Freeze();

//     if (conf.count("test_data")) {
//         cerr << "Loading test set\n";
//         test_corpus.load_oracle(conf["test_data"].as<string>());
//     }

//     for (unsigned i = 0; i < adict.size(); ++i) {
//         const string& a = adict.Convert(i);
//         if (a[0] != 'N') continue;
//         size_t start = a.find('(') + 1;
//         size_t end = a.rfind(')');
//         int nt = ntermdict.Convert(a.substr(start, end - start));
//         action2NTindex[i] = nt;
//     }

//     NT_SIZE = ntermdict.size();
//     VOCAB_SIZE = termdict.size();
//     ACTION_SIZE = adict.size();
//     possible_actions.resize(adict.size());
//     for (unsigned i = 0; i < adict.size(); ++i)
//         possible_actions[i] = i;

//     ParserBuilder parser(&model, pretrained);
//     if (conf.count("model")) {
//         ifstream in(conf["model"].as<string>().c_str());
//         boost::archive::text_iarchive ia(in);
//         ia >> model;
//     }

//     if (test_corpus.size() > 0) {
//     // if rescoring, we may have many repeats, cache them
//     unordered_map<vector<int>, unordered_map<vector<int>,double,boost::hash<vector<int>>>, boost::hash<vector<int>>> s2a2p;
//     unsigned test_size = test_corpus.size();
//     double llh = 0;
//     double right = 0;
//     double dwords = 0;
//     for (unsigned sii = 0; sii < test_size; ++sii) {
//       const auto& sentence=test_corpus.sents[sii];
//       const vector<int>& actions=test_corpus.actions[sii];
//       dwords += sentence.size();
//       double& lp = s2a2p[sentence.raw][actions];
//       if (!lp) {
//         ComputationGraph hg;
//         parser.log_prob_parser(&hg,sentence,actions,&right,true);
//         lp = as_scalar(hg.incremental_forward());
//       }
//       cout << sentence.size() << '\t' << lp << endl;
//       llh += lp;
//     }
//     cerr << "test     total -llh=" << llh << endl;
//     cerr << "test ppl (per word)=" << exp(llh / dwords) << endl;
//   }

}