from os import walk, system

_, _, filenames = next(walk('.'))

# Run each test x times with different seeds to check for segfaults by chance
# Then, use the last seed for the final output files
TEST_SEED = 1001

for name in filenames:
    if 'input' in name:
        for i in range(TEST_SEED - 50, TEST_SEED):
            cmd = f"../qwirkle {i} < {name}"
            # If last test, save output
            if i == TEST_SEED - 1:
                cmd += f" > {name.split('.')[0]}.output"
                print(cmd)
            else:
                cmd += " > /dev/null"
            return_code = system(cmd)
            # Only tests for critical errors. Logical errors can be checked by using Git's diffcheck on staging
            if return_code != 0:
                raise Exception(f"Test case {name} failed with seed {i}")
