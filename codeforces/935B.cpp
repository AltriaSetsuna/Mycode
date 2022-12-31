#include <iostream>
#include<string>

int main(int argc, char** argv) 
{
	int n;
	std::cin>>n;
	std::string a;
	std::cin>>a;
	int u=0,r=0;
	int ans=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='U')u++;
		else r++;
		if(u==r&&i<a.size()&&a[i+1]==a[i])ans++;
	}
	std::cout<<ans;
	return 0;
}
