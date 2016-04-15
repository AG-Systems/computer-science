def dict_invert(d):
    inv_dict = {v: k for k, v in d.items()}
    print inv_dict
d = {1:10, 2:20, 3:30}
dict_invert(d)
