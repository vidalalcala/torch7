local wrap = require 'cwrap'

require 'torchcwrap'

local interface = wrap.CInterface.new()

interface:print(
   [[
#include "luaT.h"
#include "TH.h"

extern void torch_Random_init(lua_State *L);
extern void torch_Random_new(lua_State *L);
   ]])

for _,name in ipairs({"seed", "initialSeed"}) do
   interface:wrap(name,
                  string.format("THRandom_%s",name),
                  {{name='Random', default=true},
                   {name="long", creturned=true}})
end

interface:wrap('manualSeed',
               'THRandom_manualSeed',
               {{name='Random', default=true},
                {name="long"}})

interface:wrap('getRNGState',
                'THByteTensor_getRNGState',
                {{name='Random', default=true},
                 {name='ByteTensor',default=true,returned=true,method={default='nil'}}
                 })

interface:wrap('setRNGState',
                'THByteTensor_setRNGState',
                {{name='Random', default=true},
                 {name='ByteTensor',default=true,returned=true,method={default='nil'}}
                 })

interface:register("random__")
                
interface:print(
   [[
void torch_random_init(lua_State *L)
{
  torch_Random_init(L);
  torch_Random_new(L);
  lua_setfield(L, -2, "_gen");
  luaL_register(L, NULL, random__);
}
]])

interface:tofile(arg[1])
