#include <iostream>
using namespace std;
class temp
{
    int data;
    int n;
    int *p;
    const int r;
    static int com;

public:
    temp(int data, int n, int *j, int u) : r(u)
    {
        this->data = data;
        this->n = n;
        p = new int[n];
        for (int i = 0; i < n; i++)
        {
            p[i] = j[i];
        }
    }
    temp() : r(0)
    {
        data = 0;
        n = 0;
        p = NULL;
    }
    temp(const temp &rm) : r(rm.r)
    {
        n = rm.n;
        data = rm.data;
        p = new int[n];
        for (int i = 0; i < n; i++)
        {
            p[i] = rm.p[i];
        }
    }
    virtual void show() const
    {
        for (int i = 0; i < n; i++)
        {
            cout << p[i] << " ";
        }
    }
    virtual temp operator+(const temp &rm)
    {
        temp result(*this);
        result.data = rm.data + data;
        result.n = rm.n + n;
        result.p = new int[result.n];
        return result;
    }
    friend temp operator*(temp &tm1, temp &tm2);
    virtual ~temp()
    {
        if (p)
        {
            delete[] p;
        }
    }
};
int temp::com = 0;
temp operator*(temp &tm1, temp &tm2)
{
    temp result;
    result.n = tm1.n * tm2.n;
    result.data = tm1.data * tm2.data;
    result.p = new int[result.n];
}
class temp2 : virtual public temp
{
    void show() const
    {
        cout << "666" << endl;
    }
};
template <typename T>
class temp3 : public temp2
{
    T *data;
    int n;

public:
    temp3(T *data,int n)
    {
        this->n=n;
        data=new T[n];
        for(int i=0;i<n;i++){
            this->data[i]=data[i];
        }
    }
    void show() const
    {
        for (int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
    }
};
int main()
{
}
