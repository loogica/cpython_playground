def test_object_not_impl():
    import dict_playground

    assert {"tester": 10} == dict_playground.my_new_dict()

def test_dict_print():
    import dict_playground

    _dict = {"tester": 10}
    assert ["tester"] == dict_playground.get_keys(_dict)

    _dict = {"tester": 10, "faster": 1000}
    assert set(["tester", "faster"]) == set(dict_playground.get_keys(_dict))

def test_enumerate_list():
    import dict_playground

    _dict = {"tester": 10, "faster": 1000}
    assert ("faster", 1000) in dict_playground.enumerate(_dict)
    assert ("tester", 10) in dict_playground.enumerate(_dict)
