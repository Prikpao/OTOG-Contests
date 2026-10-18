#include <bits/stdc++.h>

const int N = 3e5+5;
const int INVALID = -1e9-2224;

std::vector<int> weight;

long long computeAnswer(int n, std::vector<std::pair<int, int>> edge){
    int m = edge.size();
    std::set<std::pair<int, int>> setofEdge;
    for (std::pair<int, int> x : edge){
    	if (x.first == x.second) {
    		return INVALID;
    	}
        if (x.first > x.second) {
            std::swap(x.first, x.second);
        }
        if (!setofEdge.insert(x).second) {
        	return INVALID;
        }
    }
    
    long long answer = 0ll;
    int cnt = 0;

    std::vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    std::function<int(int)> findParent = [&] (int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    };

    for (int i = 0; i < m; i++){
        std::pair<int, int> pairofNode = edge[i];
        int u = findParent(pairofNode.first);
        int v = findParent(pairofNode.second);

        if (u != v){
            parent[v] = u;
            answer += weight[i];
            cnt++;
        }
    }
    if(cnt != n - 1) {
    	return INVALID;
    }
    return answer;
}

const std::string FAILSTR = "FAIL-afsdjklsdfaljkadjsiowerweiouqhnznxciwe";

void pc(double score){
    std::cout << std::fixed << score << std::endl;
    std::cerr << "translate:partial" << std::endl;
    exit(0);
}

void wa(){
	std::cout << "0.0" << std::endl;
	std::cerr << "translate:wrong" << std::endl;
	exit(0);
}

void ok(){
	std::cout << "1.0" << std::endl;
	std::cerr << "translate:success" << std::endl;
	exit(0);
}

std::string readWord(std::istream& in){
	std::string out;
	if(in >> out) return out;
	else return FAILSTR;
}

int readInt(std::istream& in, int mn = INT_MIN, int mx = INT_MAX){
	int tmp;
    in >> tmp;
	if(tmp < mn || tmp > mx){
		wa();
	}
	return tmp;
}

int main(int argc, char * argv[])
{
	std::ifstream inf(argv[1]);
	std::ifstream ans(argv[2]);
	std::ifstream ouf(argv[3]);
    int count = readInt(ouf);
	if(readWord(ouf) != "SKIBIDI_aoiqrjgoihdgva") wa();
    if(count == -1) wa();
    if(count <= 2000) ok();
    else pc((((double)55.0 - (double)(count-2001)*(double)(55)/double(1999)))/(double)70);
}
