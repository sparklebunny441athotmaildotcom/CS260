#include <iostream>
#include "stack.h"

using namespace std;

void dumpStack(stack &s)
{
    cout << "Dumping the stack" << endl;
    while (!s.isEmpty())
    {
	const coordinates result = s.pop();
	cout << "Value: " << result.x << ", " << result.y << endl;
    }
}

void pushHelper(stack &s,int x, int y)
{
    coordinates entry;

    entry.x = x;
    entry.y = y;
    s.push(entry);
}

int main()
{
    stack s;
    //stack s(5);
    coordinates entry;

    pushHelper(s,1,1);
    dumpStack(s);

    pushHelper(s,2,2);
    pushHelper(s,3,3);
    dumpStack(s);

}
