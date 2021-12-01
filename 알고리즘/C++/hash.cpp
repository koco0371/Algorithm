#include <stdio.h>
#include <string.h>
#include <memory.h>
#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096
using namespace std;


typedef struct
{
	char key[MAX_KEY + 1];
	char data[MAX_DATA + 1];
} Hash;
Hash tb[MAX_TABLE];

unsigned long hashh(const char* str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE; // 해시값을 만드는거다. "ABC" 이면  hash=(hash*32+hash+'a')%MAX_TABLE 을 ABC다 해준다. 
	}
	return hash % MAX_TABLE; //5381만 있을때 조건
}


int add(const char* key, char* data) // 상수 key
{
	unsigned long h = hashh(key);
	int cnt = MAX_TABLE;
	while (tb[h].key[0] != 0) //  tb[h].key 가 안비어있다면?
	{
		if (strcmp(tb[h].key, key) == 0) //만약 기존 키값과 들어온 키값이 같다면 아무것도 안하고 아니면 덮어쓴다.
			return 0;
		h = (h + 1) % MAX_TABLE;
	}

	strcpy_s(tb[h].key, key);
	strcpy_s(tb[h].data, data);
	return 1;

}
int find(const char* key, char* data)
{
	unsigned long h = hashh(key);
	int cnt = MAX_TABLE;

	while (tb[h].key[0] != 0 && cnt--)
	{
		if (strcmp(tb[h].key, key) == 0)
		{
			strcpy_s(data, tb[h].data);
			return 1;
		}
		h = (h + 1) % MAX_TABLE;
	}
	return 0;
}

int main()
{
	memset(tb, 0, sizeof(tb));

	int n;
	char k[MAX_KEY + 1];
	char d[MAX_DATA + 1];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k >> d;
		add(k, d);
	}


	cout << "INPUT IS : ";

	char k2[MAX_KEY + 1];
	char d2[MAX_KEY + 1];

	cin >> k2;
	if (find(k2, d2))
		cout << "OUTPUT IS : \n" << d2;
	else
		cout << "NO FIND \n";

	return 0;
}
