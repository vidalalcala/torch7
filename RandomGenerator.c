#include <general.h>

static const struct luaL_Reg torch_Random_table_ [] = {
  {NULL, NULL}
};

int torch_Random_new(lua_State *L)
{
  THRandom *gen = THRandom_new();
  luaT_pushudata(L, gen, torch_Random);
  return 1;
}

int torch_Random_free(lua_State *L)
{
  THRandom *gen= luaT_checkudata(L, 1, torch_Random);
  THRandom_free(gen);
  return 0;
}

#define torch_Random_factory torch_Random_new

void torch_Random_init(lua_State *L)
{
  luaT_newmetatable(L, torch_Random, NULL,
                    torch_Random_new, torch_Random_free, torch_Random_factory);
  luaL_register(L, NULL, torch_Random_table_);
  lua_pop(L, 1);
}
