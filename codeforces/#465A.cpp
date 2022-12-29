#include <iostream>
#include<cmath>

int divisors(int n)
{
	int ans=0;
	for(int i=2;i<=n/i;i++)
	{
		if(n%i==0)
		{
			if(i!=n/i)ans+=2;
			else ans++;
		}
	}
	return ans+1;
}
int main(int argc, char** argv) {
	int n;
	std::cin>>n;
	std::cout<<divisors(n);
	return 0;
}
