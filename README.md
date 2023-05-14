### Pluginlib ဆိုတာက ros2 pkg ထဲက plugin တွေ load/unload လုပ်လို့ရစေတဲ့ lib ပါ။ 
plugin တွေသည် ros2 မှာ ဆိုရင် dynamically load လို့ရတဲ့ class တွေပဲဖြစ်ပါတယ်။ 
plugin တွေကို  runtime မှာ load ပေးခြင်းဖြင့် application ကို မထိခိုက်ပဲ extend လုပ်ပေးလို့ရစေပါတယ်။ 
ဥပမာမှာ base class အတွက် package တစ်ခု plugin အတွက် package တစ်ခုဆောက်မယ်။
#### ပထမဆုံး base class အတွက်
```
sudo apt-get install ros-humble-pluginlib
ros2 pkg create --build-type ament_cmake polygon_base --dependencies pluginlib --node-name area_node
```
ကျန်တာတော့ include/polygon_base/regular_polygon.hpp နဲ့ CMakeLists.txt ကို ရေးပါ။
#### ဒုတိယ အနေနဲ့ plugin ဖန်တီးဖို့ package တစ်ခုဆောက်ပါ။ 
```
ros2 pkg create --build-type ament_cmake polygon_plugins --dependencies polygon_base pluginlib --library-name polygon_plugins
```
polygon_plugins.cpp ကို ကြည့်ပါ။ code ထဲက အောက်ဆုံးက macro ၃ ကြောင်းကသာ class ကို တကယ့် pluginlib ဖြစ်အောင်လုပ်ပေးထားတာပါ။  အဲ့မှာ  base class နဲ့ plugin ကိုထည့်ပေးထားရတယ်။ 
 ```
#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(polygon_plugins::Square, polygon_base::RegularPolygon)
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Triangle, polygon_base::RegularPolygon)
```
plugins.xml ကို ရေးပြီးတော့ base class နဲ့ plugins တွေကြေငြာပေးရမယ်။ ဒါမှ plugin loader က သိမှာဖြစ်တယ်။
နောက်ဆုံးအချက်ကတော့ အဲ့ဒီ xml ကို CMakeLists.txt မှာထည့်ဖို့ပဲ။
```
pluginlib_export_plugin_description_file(polygon_base plugins.xml)
```

#### စမ်းသပ်ဖို့အတွက် program ရေးမှာမို့ package အသစ်တစ်ခုဖန်တီးလိုက်ပါမယ်။
```
ros2 pkg create --build-type ament_cmake test_plugin --dependencies pluginlib polygon_base --node-name area_node
```
area_node.cpp ရေးပြီးရင် build ပြီး run ပါ။
```
colcon build --symlink-install
ros2 run test_plugin area_node
Triangle area: 43.30
Square area: 100.00
```




# ros2_plugins
