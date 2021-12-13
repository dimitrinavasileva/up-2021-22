#include <iostream>
#include <cstddef>

constexpr std::size_t N = 20;
constexpr std::size_t M = 20;

int main()
{
    int arr[N][M];
    std::size_t n, m;

    std::cin >> n >> m;
    for(std::size_t i=0; i<n; i++)
        for(std::size_t j=0; j<m; j++)
            std::cin >> arr[i][j];

    // http://c-faq.com/decl/spiral.anderson.html
    int *arr2[N];
    for(std::size_t i=0; i<n; i++)
        arr2[i] = arr[i];

    for(std::size_t i=0; i<n; i++)
    {
        for(std::size_t j=0; j<m; j++)
            std::cout << arr2[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}
