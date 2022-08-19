#include<bits/stdc++.h>
using namespace std;

/*
Input will be a URL -> Long or Short
Output will be a corresponding URL -> If long -> Short else Long

Final output for short url
www.shortenURL.com/<endpoint>

Key - Value
URL - Short URL endpoint
Short URL endpoint - URL

unordered_map<string,string> urlToShortUrl;
*/

class UrlShortner{
    private:
        unordered_map<string,string> urlToShortUrl;
        unordered_map<string,string> shortUrlToUrl;
        string baseUrl="www.shortenURL.com/";
    public:
        UrlShortner(){
            this->urlToShortUrl.clear();
            this->shortUrlToUrl.clear();
        }
        string randomURL(){
            string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            string urlEndpoint;
            int pos;
            while(urlEndpoint.size() != 7) {
                pos = ((rand() % (str.size() - 1)));
                urlEndpoint += str.substr(pos,1);
            }
            return urlEndpoint;
        }
        string generateRandomUrl(){
            //generate random url endpoint which is not present in shortUrlToUrl
            string urlEndpoint=this->randomURL();
            while(this->shortUrlToUrl.find(urlEndpoint) != this->shortUrlToUrl.end()){
                urlEndpoint=this->randomURL();
            }
            return urlEndpoint;
        }
        void getShortURL(string URL){
            if(this->shortUrlToUrl.find(URL) != this->shortUrlToUrl.end()){
                cout<<"Already shortened"<<endl;
                cout<<"Original URL :"<<this->shortUrlToUrl[URL]<<endl;
                return;
            }
            if(urlToShortUrl.find(URL)==urlToShortUrl.end()){
                string temp=this->generateRandomUrl();
                string shortURL=baseUrl+temp;
                urlToShortUrl[URL]=shortURL;
                shortUrlToUrl[shortURL]=URL;
                cout<<"Shorten URL: "<<shortURL<<endl;
                //add endpoint to the server
                return;
            }
            else{
                cout<<"You have already shortened this URL"<<endl;
                cout<<"Shorten URL: "<<urlToShortUrl[URL]<<endl;
                return;
            }
        }
};

int main(){
    UrlShortner shortner;
    shortner.getShortURL("www.google.com");
    shortner.getShortURL("https://www.geeksforgeeks.org/get-your-dream-job-with-amazon-sde-test-series/?ref=leftbar-rightbar");
    shortner.getShortURL("https://www.geeksforgeeks.org/get-your-dream-job-with-amazon-sde-test-series/?ref=leftbar-rightba");
    shortner.getShortURL("www.shortenURL.com/H03WOeq");

}