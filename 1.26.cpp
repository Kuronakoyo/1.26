// 1.26.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <stdio.h>
#include <list>
#include <vector> 


// 第1問(10点)
// 以下のクラスにコンストラクタ、デストラクタを追加してください。
// コンストラクタ、デストラクタの処理の内容はなんでも構いません

class Point
{
private:
    int x;
    int y;
    Point(int x, int y);//コンストラクタ

    ~Point()//デストラクタ
    {
        printf("出来た");
    }

};
Point::Point(int x, int y)
{
    printf("出来た");
}


// 第2問(10点)
// int型の変数をnewを使い確保してください。
// また、char型の配列をnewを使い確保してください。
// どちらもdeleteを呼び出すようにしてください。

int main()
{
    int* newInt = new int();
    int* newArray = new int[100];

    delete[] newArray;
    newArray = nullptr;

    delete newInt;
    newInt = nullptr;
}



// 第3問(15点)
// 以下の継承先クラスのデストラクタが正しく呼び出されるように、
// クラスを修正してください。

class Test
{
public:
    Test()
    {
        printf("Test\n");
    }
    ~Test()
    {
        printf("~Test\n");
    }
};
class Test2 : public Test
{
public:
    Test2()
    {
        printf("Test2\n");
    }
    ~Test2()
    {
        printf("~Test2\n");
    }
};
int main()
{
    Test* t = new Test2;
    t->~Test();

    delete t;
    return 0;
}



// 第4問(25点)
// 以下の関数をテンプレート化して、
// 様々な型で計算できるようにしてください。

template <typename T>
T Calc(T a, T b, int type)
{
    T ans = 0;
    switch (type)
    {
    case 0:
        ans = a + b;
        break;
    case 1:
        ans = a - b;
        break;
    case 2:
        ans = a * b;
        break;
    case 3:
        ans = a / b;
        break;
    }

    return ans;
}

int main()
{
    int ans1;
    float ans2;
    char ans3;

    ans1 = Calc<int>(2, 5, 0);
    ans2 = Calc<float>(10.0f, 2.5f, 3);
    ans3 = Calc<char>(10, 4, 2);

    printf("%d\n", Calc<int>(2, 5, 0));
    printf("%F\n", Calc<float>(10.0f, 2.5f, 3));
    printf("%d\n", Calc<char>(10, 4, 2));
    return 0;
}



// 第5問(25点)
// 次のプログラムを修正し、以下のような表示になるようにプログラムを作成してください。
// num = 50
// num = 40
// num = 30
// num = 20
// num = 10
// また、リストのデータが30しかない状態にしてください。その際表示は以下のになります。
// num = 30

int main()
{
    std::list<int> list;
    for (int i = 10; i <= 50; ++i)
    {
        // ここにプログラムを記述
        if (i % 10 == 0)
        {
            list.push_back(i);
        }
    }

    for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
    {
        printf("num = %d\n", *it);
    }

    // リストを修正してnum=30と表示されるようにプログラムを記述
}



// 第6問(25点)
// 第5問と同じ表示になるようにstd::vectorを使ってプログラムを記述してください。

int main()
{
    std::vector<int> vec;

    for (int i = 10; i <= 50; ++i)
    {
        if (i % 10 == 0)
        {
            vec.push_back(i);
        }
    }

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        printf("num = %d\n", *it);
    }

}



