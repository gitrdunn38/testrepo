

#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;


const char* LANGS[] = {
  "en", "Hello world",
  "fr", "Bonjour monde",
  "de", "Hallo welt",
  "pl", "Ellohay orldway",
  "zh", "Ni hao",
  "jp", "konichiwa",
  "it", "mama mia!"
};


// This is my typedef for convenience.
typedef std::map<std::string, std::string> langmap_t;


// This thing says hello.
void say_hello(int argc, char** argv, const langmap_t& langmap) {
  
  if (argc < 2) {
    cout << "Need a language!" << endl;
    return;
  }
  
  const std::string key(argv[1]);
  const langmap_t::const_iterator it = langmap.find(key);
  
  if (it == langmap.end()) {
    cout << "Language not found!" << endl;
    return;
  }
  
  cout << it->second << endl;
}


  
int main(int argc, char** argv) {
  // Build the lang map
  langmap_t langmap;
  
  const int n_langs = (sizeof(LANGS)/sizeof(LANGS[0]))/2;
  
  for (int kk = 0; kk < n_langs; kk++) {
    const std::string key(LANGS[2*kk]);
    const std::string val(LANGS[2*kk + 1]);

    langmap.insert(std::make_pair<std::string, std::string>(key, val));
  }  

  say_hello(argc, argv, langmap);

  cout << "I'm out!" << endl;
  return 0;
}




