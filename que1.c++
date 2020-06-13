#include<bits/stdc++>


int main(){
	int t;
	float a,d;
	float q,marks,u;
	string temp;
	cin>>t;
	while(t--){
			cin>>a>>d;
			vector<assignment> assignments;
			for(int i=0;i<a;i++){
					cin>>temp>>q>>u;
					assignments.push_back(assignment(u));
					for(int j=0;j<q;j++){
							cin>>temp>>marks>>u;
							assignments[i].marksTime.push_back({marks,u});
							assignments[i].maxMarks = 0;
					}
			}
			
			//algo
			maxForEachAssign(assignments);
			cout<< (int)maxForTotal(assignments,d)<<endl;
	}