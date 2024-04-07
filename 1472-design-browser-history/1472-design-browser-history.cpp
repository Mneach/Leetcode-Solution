class BrowserHistory {
public:
    vector<string> visitedUrl;
    int currentUrl;
    int lastUrl;

    BrowserHistory(string homepage) { 
        visitedUrl.push_back(homepage);
        currentUrl = 0;
        lastUrl = 0;
    }
    
    void visit(string url) {
        currentUrl += 1;
        
        if(visitedUrl.size() > currentUrl){
            visitedUrl[currentUrl] = url;
        }else{
            visitedUrl.push_back(url);
        }
        
        lastUrl = currentUrl;
    }

    string back(int steps) {
        int backIndex = max(0, currentUrl - steps);
        currentUrl = backIndex;
        return visitedUrl[currentUrl];
    }

    string forward(int steps) {
        int forwardIndex = min(lastUrl, currentUrl + steps);
        currentUrl = forwardIndex;
        return visitedUrl[currentUrl];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */