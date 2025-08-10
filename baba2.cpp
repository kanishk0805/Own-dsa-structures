#include <bits/stdc++.h>
using namespace std;
class Things
{
    public:
	double weight;
	int value;
};
class vertices
{
    public:
	double weight;
	int level, profit, bound;
};
int boundation(vector<Things> &arrItems,int &W, vertices u, int &n )
{
	if (u.weight >= W) return 0;
	int profitBound = u.profit;
	int i = u.level + 1;
	int totalWeight = u.weight;
	while ((i < n) && (totalWeight + arrItems[i].weight <= W))
	{
		totalWeight += arrItems[i].weight;
		profitBound += arrItems[i].value;
		i++;
	}
	if (i < n) profitBound += (W - totalWeight) * arrItems[i].value /arrItems[i].weight;

	return profitBound;
}

// Returns maximum profit we can get with capacity W
int knapsack(vector<Things> &arrItems, int &W,  int &n)
{
	sort(arrItems.begin(), arrItems.end(), [&](Things a, Things b) { return (a.value / a.weight) > (b.value / b.weight); });
	queue<vertices> q;
	vertices u, v;
	u.level = -1; //initializing
	u.profit =0;
    u.weight = 0;
	q.push(u);
	int maxProfit = 0;
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		if (u.level == n-1)
			continue;
        //increasing level
		v.level = u.level + 1;
		// Taking
		v.profit = u.profit + arrItems[v.level].value;
		v.weight = u.weight + arrItems[v.level].weight;
		if (v.weight <= W && v.profit > maxProfit) maxProfit = max(v.profit,maxProfit);
		v.bound = boundation(arrItems, W, v, n);
		if (v.bound > maxProfit)
			q.push(v);
        //not taking
		v.weight = u.weight;
		v.profit = u.profit;
		v.bound = boundation(arrItems, W, v, n);
		if (v.bound > maxProfit)
			q.push(v);
	}

	return maxProfit;
}

int main()
{
	cout<<"enter the number of items and weight"<<endl;
    int n,W;
    cin>>n>>W;
	cout<<"enter the Things weight and value order"<<endl;
    
	vector<Things> arrItems(n);
    for(int i=0;i<n;i++) {
        cin>>arrItems[i].weight>>arrItems[i].value;
    }
    // while(auto &i :arrItemsitems) cin>>i.value>>i.weight;

	cout << "Maximum profit = "
		<< knapsack(arrItems,W, n);

	return 0;
}
