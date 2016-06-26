with open('bad_samples') as f:
    samples = set(f.readlines())
print(''.join(sorted(samples)))

