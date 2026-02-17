#include <iostream>

#include "cpp/1706.cpp"

int main(int argc, char const *argv[])
{
    
    auto sol = Solution();
    //auto grid = std::vector<std::vector<int>>{{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    //auto grid = std::vector<std::vector<int>>{{-1}};
    auto grid = std::vector<std::vector<int>>{{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    auto ans = sol.findBall(grid);
    for (auto i : ans)     std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
