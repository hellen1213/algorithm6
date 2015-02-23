#include <iostream>  
#include <algorithm>
#include <string.h>
#include "Graph.h"  
     
const int max = 1000;

int cicles[ max ];

bool lequal(const data_t t1, const data_t t2)
{
	double d1 = t1.second;
	double d2 = t2.second;
	return d1 < d2;
}

std::vector<data_t> Kruskal( Graph G )
{
	int i, number;
	std::vector<data_t> mst;
	mst.clear();

	std::vector<data_t> edges = G.sorted_edges();

	for( i=0; i < G.V(); i++) cicles[ i ] = i;

	while( (int) mst.size() < ( G.V() - 1) && edges.size() )
	{
		data_t dt = edges[ 0 ];
		std::pair<int,int> p = dt.first;
		int vi = p.first;
		int vj = p.second;

		if( cicles[ vi ] != cicles[vj] )
		{
			number = cicles[ vj ];
			for( i=0; i < G.V(); i++ ) 
			{
				if( cicles[ i ] == number )
				{
					cicles[ i ] = cicles[ vi ];
				}
			}

			mst.push_back( dt );
		}

		edges.erase( edges.begin(), edges.begin() + 1 );
    }

	return mst;
}

std::vector<data_t> Kruskal2( Graph G )
{
	int i, number;
	std::vector<data_t> mst;
	mst.clear();

	std::vector<data_t> edges = G.sorted_edges2();

	for( i=0; i < G.V(); i++) cicles[ i ] = i;

	while( (int) mst.size() < ( G.V() - 1) && edges.size() )
	{
		data_t dt = edges[ 0 ];
		std::pair<int,int> p = dt.first;
		int vi = p.first;
		int vj = p.second;

		if( cicles[ vi ] != cicles[vj] )
		{
			number = cicles[ vj ];
			for( i=0; i < G.V(); i++ ) 
			{
				if( cicles[ i ] == number )
				{
					cicles[ i ] = cicles[ vi ];
				}
			}

			mst.push_back( dt );
		}

		edges.erase( edges.begin(), edges.begin() + 1 );
    }

	return mst;
}


int main()  
{  int a1[17];
	int a2[17];
	int i=0, j;

	Graph G( 20, true );  
    
	G.insert( 1, 2, 80);  
	G.insert( 5, 9, 73 ); 
	G.insert( 9, 13, 69 );  
	G.insert( 2, 3, 10 ); 
	G.insert( 5, 7, 20 ); 
	G.insert( 5, 2, 74 ); 
	G.insert( 9, 18, 15 ); 
	G.insert( 13, 14, 21); 
	G.insert( 9, 1, 92 ); 
	G.insert( 13, 2, 59 );
	G.insert( 20, 4, 6 );
	G.insert( 18, 17, 17 );
	G.insert( 11, 3, 74 );
	G.insert( 7, 18, 83 );
	G.insert( 7, 12, 27 );   
	G.insert( 1, 10, 16 );
	G.insert( 5, 15, 47 );
	G.insert( 20, 14, 94 );
	G.insert( 14, 18, 77 );
	G.insert( 2, 4, 30 );
	G.insert( 11, 14, 62 );
	G.insert( 3, 20, 85 );
	G.insert( 11, 7, 62 );
	G.insert( 6, 10, 87 );
	G.insert( 12, 15, 81 );
	G.insert( 3, 19, 39 );
	G.insert( 9, 8, 45 );
	G.insert( 19, 4, 65 );
	G.insert( 8, 16, 70 );
	G.insert( 15, 17, 64 );
	G.insert( 1, 11, 32 );
	G.insert( 11, 6, 43 );
	G.insert( 12, 6, 87 );
	G.insert( 12, 19, 70 );
	G.insert( 7, 16, 39 );
	G.insert( 13, 6, 22 );
	G.insert( 4, 16, 68 );
	G.insert( 17, 10, 56 );
	G.insert( 19, 15, 71 );  
      
    G.show();     

	std::cout<<std::endl;
	std::cout <<"final result is: "<< std::endl;
	std::cout<<std::endl;

	std::vector<data_t> vec = Kruskal( G );
	std::vector<data_t>::iterator vec_it = vec.begin();

	for ( ; vec_it != vec.end(); vec_it++ )
	{
		std::pair<int,int> p = (*vec_it).first;
		double weight = (*vec_it).second;
		
		std::cout << p.first << " " << p.second << " " << weight << std::endl;
		G.remove(p.first, p.second);
	}

	std::cout<<"---------------------"<<std::endl;
	G.show();
	std::cout<<"=======the edges left for the spanning tree are: =============="<<std::endl;
	// do kruskal's algorithm to the left edges 
	std::vector<data_t> vec1 = Kruskal2( G );
	std::vector<data_t>::iterator vec_it1 = vec1.begin();
	for ( ; vec_it1 != vec1.end(); vec_it1++ )
	{
		std::pair<int,int> p = (*vec_it1).first;
		double weight = (*vec_it1).second;
		
		std::cout << p.first << " " << p.second << " " << weight << std::endl;

		a1[i] = (int)p.first;
		a2[i] = (int)p.second;
		i++;
		
//		std::cout<<"--"<<a1[i]<<","<<p.second<<std::endl;
	}
	//classify
//	for(j=0; j<i; j++){
//		std::cout <<a1[i] <<" "<<a2[i]<<std::endl;
//	}

    return 0;    
}  





