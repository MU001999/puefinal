#include "PUEF.hpp"



int main(int argc, char *argv[])
{
    // Spider spdr("blog.sina.com.cn");
    Spider spdr("house.people.com.cn");
    // Spider spdr("yangsheng.gmw.cn");
    // Spider spdr("house.people.com.cn/n1/2018/0808/c164220-30217070.html", "house.people.com");
    // Spider spdr("house.people.com.cn/GB/416283/421382/index.html");

    std::queue<std::pair<std::string, std::string>> results;

    std::thread request_thread([&] { spdr.run(results); });

    std::thread parse_thread([&]
    {
        while (!spdr.finish() || !results.empty())
        {
            if (results.empty()) continue;

            auto result = results.front();
            results.pop();

#ifdef DEBUG
            std::cout << "[DEBUG] [READY TO PARSING] " << result.first << std::endl;
#endif // DEBUG

            Serialization::obj2file(Parser::parser(result), "./results");
        }
    });

    request_thread.join();
    parse_thread.join();

    return 0;
}
