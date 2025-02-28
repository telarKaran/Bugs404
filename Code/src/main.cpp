#include "../include/header.h"
using namespace std;


bool sortcol(const vector<string>& v1, const vector<string>& v2)
{
    return v1[2] < v2[2];
}

bool sortcol2(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] > v2[0];
}

int calculateFunFactor(int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2){
	int numberOfDays = day;
	int totalTavelCost = 0;
	int totalStayCost = 0;
vector<vector<int>>  activities;
	// vector<int> locations;
	int Funfactor =0 ;

	for (int k = 0; k < path_index-1; k++){
totalTavelCost += stoi(v2[path[k+1]+1][path[k]+1]);
	}

	for (int k = 0; k < path_index; k++){

				
					for(int i=0;i<v.size();i++){
					
  
	vector<int> v1;
						if(stoi(v[i][2])==(path[k]+1)){
						
							v1.push_back(stoi(v[i][1]));
							v1.push_back(stoi(v2[path[k]+1][path[k]+1]));
							v1.push_back(path[k]);
						}
							if(stoi(v[i][2])==(path[k]+1)){
activities.push_back(v1);
							}
					}
					  
				}

					sort(activities.begin(), activities.end(), sortcol2);

	
	// for(int i=0;i<activities.size();i++)
	// {
	// 	for(int j=0;j<activities[i].size();j++)
	// 	{
	// 		cout<<activities[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	for(int i=0;i<numberOfDays;i++)
	{
		int mapForLoc[] = {0};
		if(mapForLoc[activities[i][2]]==1){
activities[i][1] = 0;
		}
		else{
			mapForLoc[activities[i][2]]=1;
		}
		
		
	}

	for(int i=0;i<numberOfDays;i++)
	{
		
			Funfactor +=activities[i][0];
		totalStayCost += activities[i][1];
	}
int funAns =(Funfactor)/(totalStayCost+totalTavelCost);
	return funAns;
}
 
 
class Graph {
    int V; // No. of vertices in graph
    list<int>* adj; // Pointer to an array containing
                    // adjacency lists
 public:
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int, int, int, bool[], int[], int&,  vector< vector<string> > &v, vector< vector<string> > &v2,vector<vector<int>> &FunFac);
 

    Graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d, int day, vector< vector<string> > &v, vector< vector<string> > &v2, vector<vector<int>> &FunFac);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
 
// Prints all paths from 's' to 'd'  ,  vector< vector<string> > &v, vector< vector<string> > &v2
void Graph::printAllPaths(int s, int d, int day,  vector< vector<string> > &v, vector< vector<string> > &v2 , vector<vector<int>> &FunFac)
{

 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
 
    // Create an array to store paths
    int* path = new int[V];
    int path_index = 0; // Initialize path[] as empty
 
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, day, visited, path, path_index,v,v2, FunFac);
}
 
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, int day, bool visited[],
                              int path[], int& path_index,  vector< vector<string> > &v, vector< vector<string> > &v2,vector<vector<int>> &FunFac)
{
    // Mark the current node and store it in path[]
		
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print
    // current path[]
    if (u == d) {
		
			int funAns = calculateFunFactor(path,path_index,day,v,v2);
		
		 vector<int> valueOfPath;
		 valueOfPath.push_back(funAns);
        for (int i = 0; i < path_index; i++){
					valueOfPath.push_back(path[i]);
					
				}
            	FunFac.push_back(valueOfPath);
        
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current
        // vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, day,visited, path,
                                  path_index, v,v2, FunFac);
    }
 
    // Remove current vertex from path[] and mark it as
    // unvisited
    path_index--;
    visited[u] = false;
}


int main() {

vector<vector<string>> Activity_Table;
vector<vector<string>> Associated_Cost;

vector<vector<int>> FinalFunFactot;

vector<string> row;
string line, word;
string fname = "../data/SOI_workbookCSV.csv";
string fname2 = "../data/SOI_workbookLocationCSV.csv";



fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			Activity_Table.push_back(row);
		}
	}
	else{cout<<"Could not open the file\n";}


	fstream file2 (fname2, ios::in);
	if(file2.is_open())
	{
		while(getline(file2, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			Associated_Cost.push_back(row);
		}
	}
	else{cout<<"Could not open the file 2\n";}


 // Data Cleaning

 int columnIndex = 1;
 int funFacIndex = 0;
 for_each(Activity_Table.begin(), Activity_Table.end(), 
    [&](vector<string>& row) {
        row.erase(next(row.begin(), columnIndex));

				string loc = Activity_Table[funFacIndex][2].substr(4);
				Activity_Table[funFacIndex][2] = loc;
				// cout<<	Activity_Table[funFacIndex][columnIndex]<<endl;
				if(	Activity_Table[funFacIndex][columnIndex] == "HIGH"){
					Activity_Table[funFacIndex][columnIndex] = "50";
				}
				else if(	Activity_Table[funFacIndex][columnIndex] == "MEDIUM"){
					Activity_Table[funFacIndex][columnIndex] = "20";
				}
				else if(	Activity_Table[funFacIndex][columnIndex] == "LOW"){
					Activity_Table[funFacIndex][columnIndex] = "5";
				}
				funFacIndex++;
    });

    Activity_Table.erase(Activity_Table.begin());

		sort(Activity_Table.begin(), Activity_Table.end(), sortcol);




 Graph g(5);

 for(int i=1;i<Associated_Cost.size();i++){
		for(int j=1;j<5;j++)

		{
			int cost  =  stoi(Associated_Cost[i][j]);
			// cout<<"Cost :"<<cost<<endl;
    
				int x = i-1;
				int y = j-1;
				// cout<<x<<"  "<<y<<"==="<<endl;
       g.addEdge(y,x);
      
}
 }
	


		
    int s , d, day;
		cout<<"Enter the Starting Location Between 1 to 5 : ";
    cin>>s;
		cout<<endl;
		cout<<"Enter the Ending Location Between 1 to 5: ";
		cin>>d;
		cout<<endl;
		cout<<"Enter the Number of Days : ";
		cin>>day;
		cout<<endl;
		if(s >5 || d>5 ){
			cout<<"Please Enter Number between 1 to 5"<<endl;
			return 0;
		}

    g.printAllPaths(s-1, d-1,day, Activity_Table,Associated_Cost ,FinalFunFactot);


sort(FinalFunFactot.begin(), FinalFunFactot.end(), sortcol2);
			


	cout<<"Maximum Funfactor : "<<FinalFunFactot[0][0]<<endl;
	cout<<"Path Covered is : ";
	for(int i=0;i<1;i++)
	{
		for(int j=1;j<FinalFunFactot[i].size();j++)
		{
			cout<<FinalFunFactot[i][j]+1<<" ";
		}
		cout<<"\n";
	}
	return 0;

}