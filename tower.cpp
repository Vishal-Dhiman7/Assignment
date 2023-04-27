
#include <bits/stdc++.h>
using namespace std;
#include <vector>
vector<int> findMaximumNetwork(vector<vector<int>>& tower, int radius){
    vector<int> maxNetworkCordinate(2,0);
    int best = 0;
    for(int i = 0; i<tower.size(); i++){
        int x1 = tower[i][0];
        int y1 = tower[i][1];
        int q = tower[i][2];
        for(int j = 0; j<tower.size(); j++){
            if(i != j){
                int x2 = tower[j][0];
                int y2 = tower[j][1];
                int q2 = tower[j][2];
                //euclidean distance formula
                double distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
                //distance should be less than equal radius for good connection
                if(distance <= (radius)){
                    q += (q2/(1+distance));
                }
            }
        }
        if(best < q){
            best = q;
            maxNetworkCordinate[0] = tower[i][0];
            maxNetworkCordinate[1] = tower[i][1];
        }
        else if(best == q){
            best = q;
            if(maxNetworkCordinate[0] == tower[i][0]){
                if(maxNetworkCordinate[1] > tower[i][1]){
                    maxNetworkCordinate[0] = tower[i][0];
                    maxNetworkCordinate[1] = tower[i][1];
                }
            }
            else{
                if(maxNetworkCordinate[0] > tower[i][0]){
                    maxNetworkCordinate[0] = tower[i][0];
                    maxNetworkCordinate[1] = tower[i][1];
                }
            }
        }
    }
    return maxNetworkCordinate;
}

int main()
{
    vector<vector<int>> tower;
    int n;
    cout << "enter the tower count" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int x, y, q;
        cout << "first enter x cordinate then Y then quality factor" << endl;
        cin >> x >> y >> q;
        temp.insert(temp.end(), {x, y, q});
        tower.push_back(temp);
    }
    int radius;
    cout<<"enter the the radius"<<endl;
    cin>>radius;
    vector<int> ans = findMaximumNetwork(tower,radius);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}