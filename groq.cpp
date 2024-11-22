#include <iostream>
#include <string>
#include <future>
#include <cstdlib>
#include <limits>
#include <map>
#include <vector>
#include <memory>
#include <stdexcept>
#include <thread>
#include <chrono>

class Groq
{
public:
    Groq(const std::string &apiKey) : apiKey(apiKey) {}
    std::map<std::string, std::vector<std::map<std::string, std::string>>> chatCompletion(const std::string &content)
    {
        return {
            {"choices", {{{"role", "assistant"}, {"content", "This is a simulated response to: " + content}}}}};
    }

private:
    std::string apiKey;
};

std::string prompt(const std::string &question)
{
    std::string answer;
    std::cout << question;
    std::getline(std::cin, answer);
    return answer;
}

int main()
{
    std::string apiKey = std::getenv("GROQ_API_KEY") ? std::getenv("GROQ_API_KEY") : "";
    Groq groq(apiKey);

    std::cout << "\033[48;5;235m\033[97m\033[1mAI CLI\033[0m\n";
    std::cout << "=============================================\n";
    std::cout << "ENTER PROMPT AND PRESS ENTER TO SEE THE RESULT\n";
    std::cout << "CTRL + C TO EXIT\n";
    std::cout << "=============================================\n";

    std::string prev;
    while (true)
    {
        std::string content = prompt("enter your prompt: ");
        auto chatCompletion = groq.chatCompletion(content);
        prev = chatCompletion["choices"][0]["content"];
        std::cout << "\033[48;5;46m\033[90m\033[1mAI ANSWER : \033[0m" << prev << "\n";
    }

    return 0;
}
