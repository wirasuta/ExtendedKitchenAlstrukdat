ing_list = ['sendok', 'garpu', 'eskrim', 'nasi', 'roti', 'spaghetti', 'pisang', 'stroberi', 'telur', 'ayamgoreng', 'patty', 'sosis', 'bolognese', 'carbonara', 'keju']

ing_count = 1
for ig in ing_list:
    c_count = 1
    print("IngName(Ingredient(*R, {})).TabKata[0] = ' ';")
    for c in ig:
        print("IngName(Ingredient(*R, {})).TabKata[{}] = '{}';".format(ing_count,c_count,c))
        c_count+=1
    print("IngName(Ingredient(*R, {})).Length = {};".format(ing_count,len(ig)))
    print("PosIngredients(Ingredient(*R, {})) = MakePOINT(1, {});\n".format(ing_count,(ing_count+1)))
    ing_count+=1
