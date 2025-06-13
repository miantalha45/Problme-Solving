class Solution {
public:
    unordered_map<string, string> map;
    string base_url = "http://tinyurl.com/";
    int counter = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = to_string(counter);
        string shortUrl = base_url + key;

        map[key] = longUrl;
        counter++;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(base_url.length());
        return map.count(key) > 0 ? map[key] : "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));