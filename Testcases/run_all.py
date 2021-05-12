from os import walk, system

_, _, filenames = next(walk('.'))

for name in filenames:
    if 'input' in name:
        cmd=f"../qwirkle < {name} > {name.split('.')[0]}.output"
        print(cmd)
        system(cmd)
