def test_object_not_impl():
    import object_protocol_playground as opp

    assert opp.not_impl() == NotImplemented


def test_object_raise_not_impl():
    import object_protocol_playground as opp

    try:
        opp.raise_not_implemented()
        assert False
    except NotImplementedError:
        assert True


def test_object_print():
    import object_protocol_playground as opp

    assert opp.print() == None


def test_object_hasattr():
    import object_protocol_playground as opp

    class ob:
        def __init__(self, attr):
            self.attr = attr

    o = ob("attr")

    assert opp.hasattr(o, "attr")
    assert not opp.hasattr(o, "aattr")

def test_object_getattr():
    import object_protocol_playground as opp

    class ob:
        def __init__(self, attr):
            self.attr = attr

    o = ob("value")

    assert "value" == opp.getattr(o, "attr")
