// Counting based window selection
// Irvanda Kurniadi Virdaus@2016

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	//write trace file
	// ofstream trace;
	// trace.open("trace.txt");
	
	//Global parameter
	int i,j,k;
	int count;
	int empty;
	int tot_fail;
	int tot_suc;
	int node[10];
	bool is_suc;
	
	//seed srand
	srand(time(NULL));
	
	for ( int n = 2; n <= 10; n+=2)
	{
		for(int cw = 4; cw <=32; cw*=2)
		{
			tot_fail = 0;
			tot_suc = 0;
			
			for (i = 1; i<=1000000; ++i)
			{
				is_suc = false;
				
				//get backoff timer
				for (j = 0; j < n; ++j)
					node[j] = rand() % cw;
				
				//check fail and success
				for (j = 0; j < cw; ++j)
				{
					count = 0;
					for(k = 0; k < n; ++k)
					{
						if (node[k] == j)
							count++;
					}
					
					if (count == 1)
						is_suc = true;
				}
					
				if(is_suc)
					tot_suc++;
				else
					tot_fail++;
			}
			cout << "n = " << n << ", cw = "<< cw <<", pf = " << (double)tot_fail/1000000 << ", ps = " << (double)tot_suc/1000000 << endl;
		}
	}
	
	return 0;
}