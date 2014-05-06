//想不起来
class EmployManager {
  public:
    int maximumEarnings(vector <int> value, vector <string> earning) {
      int ret = 0;
      for(int i = 0; i<(int)earning.size(); i++) {
        for(int j = 0; j<i; j++) {
          ret -= earning[i][j]-'0';
        }
      }
      for(int i = 0; i<(int)earning.size(); i++) {
        int atual = 0;
        for(int j = 0; j<(int)earning[i].size(); j++) {
          atual += earning[i][j]-'0';
        }
        if(atual >= value[i]) ret += atual-value[i];
      }
      return ret;
    }
  };