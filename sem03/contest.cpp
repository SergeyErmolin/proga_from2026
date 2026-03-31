#include <iostream>

using namespace std;

#define N 5
#define M 2

void readArray(int (&arr)[N]) {
    for ( int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
}

void printArray(int (&arr)[N*M]) {
    for ( int i = 0; i < N*M-1; i++)
    {
        std::cout << arr[i] << ' ';
    }
	std::cout << arr[N*M-1] << std::endl;
}

void reverseArray(int (&arr)[N]) {
    int temp;
    for (int i = 0; i < N/2; i++)
    {
        temp = arr[N-1-i];
        arr[N-1-i] = arr[i];
        arr[i] = temp;
    }
}

void shiftArrayRight(int (&arr)[N]) {
    int pod_1 = arr[N-1], pod_2;
    for (int i = 0; i < N; ++i)
    {
        pod_2 = arr[i];
        arr[i] = pod_1;
        pod_1= pod_2;
    }
}

void moveNegativeToEnd(int (&array)[N]) {
    bool togl = true;
    while (togl)
    {
        togl = false;
        for (int i = 0; i < N-1; ++i) {
            if ((array[i] < 0) and (array[i+1] >= 0)) {
                int tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                togl = true;
            }
        }
    }
}

void mergeArrays(int (&lhs)[N], int (&rhs)[N], int (&res)[2 * N]) {
    for (int i = 0; i < N; ++i)
    {
        res[i] = lhs[i];
        res[N+i] = rhs[i];
    }
}

int findLastZero(int (&array)[N]) {
    int l_idx = 0, r_idx = N-1, c_idx;
    while (l_idx < r_idx)
    {
        c_idx = (l_idx + r_idx + 1)/2 ;
        if (array[c_idx] == 1)
        {
            r_idx = c_idx-1;
        } else {
            l_idx = c_idx;
        }
    }
    return l_idx;
}

void printTransposed(int (&array)[N][M]) {
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; j++)
        {
            cout << array[j][i] << ' ';
        }
        cout << endl;
    }
}

int trace(int (&array)[N * N]) {
    int tr = 0;
    for (int i = 0; i < N; ++i)
    {
        tr += array[i + (N)*i];
    }
    return tr;
}

void sort2d(int (&array)[N][M]) {
    int line[N*M];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            line[i + N*j] = array[i][j];
        }
    }
    //line sort
    bool togl = true;
    while (togl)
    {
        togl = false;
        for (int i = 0; i < N*M-1; ++i) {
            if (line[i] > line[i+1]) {
                int tmp = line[i];
                line[i] = line[i+1];
                line[i+1] = tmp;
                togl = true;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            array[i][j] = line[j + M*i];
        }
    }
}

int find_unique(int (&a)[N]) {
    int r = 0;
    for (int i = 0; i < N; ++i)
    {
        r ^= a[i];
    }
    return r;
}

int main() {
    int arr[N];
    //int (array)[N][M] = {{3,4}, {1,2}, {5,6}, {7,8}};
    readArray(arr);
    //sort2d(array);
    cout << find_unique(arr);
    return 0;
}
// .\a.exe > output.txt

    // int l_idx =0, r_idx = N - 1, i;
    // bool togl;
    // while (l_idx < r_idx) {
    //     togl = true;
    //     for (i = l_idx + 1; i <= r_idx; ++i){
    //         if (a[l_idx] == a[i])
    //         {
    //             togl = false;
    //             if ((i - l_idx - 1)%2 == 0)
    //             {
    //                 l_idx = i + 1;
    //                 break;
    //             } else {
    //                 r_idx = i - 1;
    //                 ++l_idx;
    //                 break;
    //             }
    //         }
    //     }
    //     if (togl) break;
    // }
    // return a[l_idx];