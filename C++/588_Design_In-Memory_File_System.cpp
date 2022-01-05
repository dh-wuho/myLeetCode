class FileSystem {
public:
    unordered_map<string, set<string>> dirs;
    unordered_map<string, string> files;
    
    FileSystem() {
        dirs["/"];
    }
    
    vector<string> ls(string path) {
        if(files.find(path) != files.end()) {
            int deliIndex = path.find_last_of('/');
            return {path.substr(deliIndex + 1)};
        }
        set<string> res = dirs[path];
        return vector<string>(res.begin(), res.end());
    }
    
    void mkdir(string path) {
        stringstream ss(path);
        string curr;
        string last = "";
        while(getline(ss, curr, '/')) {
            if(curr.empty()) {
                continue;
            }
            if(last.empty()) {
                dirs[last + "/"].insert(curr);
            }
            else {
                dirs[last].insert(curr);
            }
            last = last + "/" + curr;
        }
    }
    
    void addContentToFile(string filePath, string content) {
        int deli = filePath.find_last_of('/');
        string dir = filePath.substr(0, deli);
        string file = filePath.substr(deli + 1);
        if(dir.empty()) {
            dir = "/";
        }
        if(dirs.find(dir) == dirs.end()) {
            mkdir(dir);
        }
        dirs[dir].insert(file);      
        files[filePath] += content;
    }
    
    string readContentFromFile(string filePath) {
        return files[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */