def test_number_check():
    import number_protocol_playground as npp

    assert npp.check(1)
    assert not npp.check("a")

def test_number_add():
    import number_protocol_playground as npp

    assert npp.add(1, 2) == 3
