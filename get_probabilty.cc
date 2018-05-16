#include "nt-parser/nt-parser.h"
int main(int argc, char** argv) {
    
    cnn::Initialize(argc, argv);

    std::cout << "COMMAND LINE:"; 
    for (unsigned i = 0; i < static_cast<unsigned>(argc); ++i) cout << ' ' << argv[i];
    cout << endl;
    unsigned status_every_i_iterations = 100;

    po::variables_map conf;
    InitCommandLine(argc, argv, &conf);
    IMPLICIT_REDUCE_AFTER_SHIFT = conf.count("explicit_terminal_reduce") == 0;
    USE_POS = conf.count("use_pos_tags");
    if (conf.count("dropout"))
      DROPOUT = conf["dropout"].as<float>();
    LAYERS = conf["layers"].as<unsigned>();
    INPUT_DIM = conf["input_dim"].as<unsigned>();
    PRETRAINED_DIM = conf["pretrained_dim"].as<unsigned>();
    HIDDEN_DIM = conf["hidden_dim"].as<unsigned>();
    ACTION_DIM = conf["action_dim"].as<unsigned>();
    LSTM_INPUT_DIM = conf["lstm_input_dim"].as<unsigned>();
    POS_DIM = conf["pos_dim"].as<unsigned>();
    if (conf.count("train") && conf.count("dev_data") == 0) {
      cerr << "You specified --train but did not specify --dev_data FILE\n";
      return 1;
    }
    if (conf.count("alpha")) {
      ALPHA = conf["alpha"].as<float>();
      if (ALPHA <= 0.f) { cerr << "--alpha must be between 0 and +infty\n"; abort(); }
    }
    if (conf.count("samples")) {
      N_SAMPLES = conf["samples"].as<unsigned>();
      if (N_SAMPLES == 0) { cerr << "Please specify N>0 samples\n"; abort(); }
    }
    
    ostringstream os;
    std::cout << "ntparse"
      << (USE_POS ? "_pos" : "")
      << '_' << IMPLICIT_REDUCE_AFTER_SHIFT
      << '_' << LAYERS
      << '_' << INPUT_DIM
      << '_' << HIDDEN_DIM
      << '_' << ACTION_DIM
      << '_' << LSTM_INPUT_DIM
      << "-pid" << getpid() << ".params";
    const string fname = os.str();
    std::cout << "PARAMETER FILE: " << fname << endl;
    bool softlinkCreated = false;

    Model model;

    parser::TopDownOracle corpus(&termdict, &adict, &posdict, &ntermdict);
    parser::TopDownOracle dev_corpus(&termdict, &adict, &posdict, &ntermdict);
    parser::TopDownOracle test_corpus(&termdict, &adict, &posdict, &ntermdict);
    corpus.load_oracle(conf["training_data"].as<string>(), true);	
    corpus.load_bdata(conf["bracketing_dev_data"].as<string>());


}