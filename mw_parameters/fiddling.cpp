#include "fiddling.h"

using namespace mw;
using namespace std;


map<meta_token, vector<MWParameterDescription> > MWBaseParameters::parameter_table;


int main(){
  
  using namespace mw;
  
  shared_ptr<ComponentRegistry> reg(new ComponentRegistry());

  map<string, string> sparams;
  sparams["frames_per_second"] = "12.0";
  sparams["a_number"] = "14";
  sparams["a_variable"] = "my_awesome_variable";
    
  
  MyCustomObject factory;
  shared_ptr<Component> o = factory.createComponent(sparams, reg);
  o->printStuff();
  
  return 0;
}
