from os import walk, system

_, _, filenames = next(walk('.'))

TEST_SEED = 1000

for name in filenames:
    if 'input' in name:
        cmd = f"../qwirkle {TEST_SEED} < {name} > {name.split('.')[0]}.output"
        print(cmd)
        system(cmd)
