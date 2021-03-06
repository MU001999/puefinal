#pragma once


class Spider
{
private:

    bool finish_status;
    std::string host;
    std::string url_limit;
    std::set<std::string> processed;
    std::queue<std::string> unprocessed;


    // check if the url has been processed
    bool has_processed(const std::string &url);

    // check if the url is legal & complete it
    bool is_legal_and_complete(std::string &url, const std::string &base);

    // check if the url meets the limit
    bool meet_limit(const std::string &url);

    std::vector<std::string> gen_urls(const std::string &str, const std::string &base);

public:

    Spider(std::string target, const std::string url_limit = "");


    const bool finish();

    void run(std::queue<std::pair<std::string, std::string>> &results);
};