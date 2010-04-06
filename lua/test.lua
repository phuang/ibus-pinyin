print(ime.get_version())

print(ime.trim_string("   Hello World!   "))

print(ime.trim_string_right("   Hello World!   "))

tab = ime.split_string("aa..bb..cc", "..");
for i,v in ipairs(tab) do print(i, v) end

tab = ime.split_string("aa..bb..cc", "..");
print(ime.join_string(tab, ", "));

print(ime.join_string({}, ".."));

_MAPPING_TABLE = [[
a 啊
b 不,吧
c 从,穿,出
]]

_MAPPING = ime.parse_mapping(_MAPPING_TABLE, "\n", " ", ",")
for k,v in pairs(_MAPPING) do 
  print(k, ":")
  for i, m in ipairs(v) do
    print(i, m)
  end
end


print("test finished...");
