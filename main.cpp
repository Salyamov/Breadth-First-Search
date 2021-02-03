#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

vector < vector<int> > g; //граф
int n = 12; //кол-во вершин
int s = 0; //стартовая вершина

void bfs(int target)
{
	queue <int> q;
	q.push(s);
	vector<bool> used(n);
	vector<int> d(n);//массив длин путей
	vector<int> p(n);//массив предков
	used[s] = true;
	p[s] = -1;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (size_t i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if (!used[to])//если не загорелась
			{
				used[to] = true;//поджигаем
				q.push(to);//добавляем в конец очереди
				d[to] = d[v] + 1;
				p[to] = v;

				/*
				cout << "i was here " << v << "->" << to << "\n";
				cout << "length: " << d[to] << "\n";
				*/
			}
		}
	}

	if (!used[target])
	{
		cout << "No path!";
	}
	else
	{
		vector<int> path;
		for (int v = target; v != -1; v = p[v])
		{
			path.push_back(v);
		}
		reverse(path.begin(), path.end());
		cout << "Path: ";
		for (size_t i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
	}
}



void readGraf()
{
	g.resize(12);

	g[0].push_back(1);
	g[0].push_back(2);
	g[0].push_back(3);
	g[0].push_back(6);

	g[1].push_back(0);
	g[1].push_back(9);

	g[2].push_back(0);
	g[2].push_back(4);
	g[2].push_back(5);

	g[3].push_back(0);

	g[4].push_back(2);
	g[4].push_back(7);

	g[5].push_back(2);
	g[5].push_back(7);
	g[5].push_back(9);

	g[6].push_back(0);

	g[7].push_back(4);
	g[7].push_back(5);
	g[7].push_back(8);

	g[8].push_back(7);

	g[9].push_back(1);
	g[9].push_back(5);
	g[9].push_back(10);

	g[10].push_back(11);

	g[11].push_back(10);

}

int main()
{
	readGraf();
	bfs(11);

	//printGraf();

	return 0;
}