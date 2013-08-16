def test_exec_unraisable():
    import io
    import sys
    import error_handling

    class Dummy:
        def __repr__(self):
            return "Unraisable Error"

    fake_stderr = io.StringIO()
    sys.stderr = fake_stderr
    error_handling.exec_unraisable_exception(Dummy())

    assert "Exception  in (Unraisable Error,) ignored\n" == sys.stderr.getvalue()
