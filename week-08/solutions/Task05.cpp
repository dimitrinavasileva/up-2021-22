#include<isostream>

constexpr int SIZE_N = 20;
constexpr int SIZE_M = 30;
constexpr int SIZE_K = 40;

void eneterMatrixAElements(int array[][SIZE_M], int n, int m)
{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				std::cin << array[i][j];
}

void eneterMatrixBElements(int array[][SIZE_K], int m, int k)
{
		for(int i = 0; i < m; i++)
			for(int j = 0; j < k; j++)
				std::cin << array[i][j];
}

void findProduct(int A[][SIZE_M],int B[][SIZE_K], int C[SIZE_N][SIZE_K], int n, int m, int k)
{
	for(int i = 0; i < n; i++)
	{
			for(int j = 0; j < k; j++)
			{
					C[i][j] = 0;
					for(int l = 0; l < m; l++)
					{
						C[i][j] += A[i][l] * B[l][j];
					}
			}
	}
}

void printMatrix(int C[SIZE_N][SIZE_K], int n, int k)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			std::cout << " " << array[i][j];
		}
		std::cout<<endl;
	}
}

int main()
{
	int n; std::cout << "N: "; std::cin >> n;
	
	int m; std::cout << "M: "; std::cin >> m;
	
	int k; std::cout << "K: "; std::cin >> k;
	
	int A[SIZE_N][SIZE_M];
	int B[SIZE_M][SIZE_K];
	int C[SIZE_N][SIZE_K];
	
	eneterMatrixAElements(A,n,m);
	eneterMatrixBElements(B,m,k);
	
	findProduct(A,B,C,n,m,k);
	
	printMatrix(C,n,k);

	return 0;
}