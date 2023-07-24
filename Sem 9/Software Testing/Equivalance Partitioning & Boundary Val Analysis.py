def validate(code: int) -> str | None :
    if 100 <= code <= 199:
        return 'informational'
    elif 200 <= code <= 299:
        return 'successful'
    elif 300 <= code <= 399:
        return 'redirection'
    elif 400 <= code <= 499:
        return 'client error'
    elif 500 <= code <= 599:
        return 'server error'
    
    return None

    
import unittest

class TestValidate(unittest.TestCase):
    
    # Beyond lower end
    def test_with_negative_code(self):
        # Method Invocation
        res = validate(-1)
        # Assertion
        self.assertIsNone(res)
        
    def test_with_code_less_than_100(self):
        # Method Invocation
        res = validate(99)
        # Assertion
        self.assertIsNone(res)

    # Informational Responses
    def test_with_code_100(self):
        # Method Invocation
        res = validate(100)
        # Assertion
        self.assertEqual(res, 'informational')
                
    def test_with_code_1xx(self):
        # Method Invocation
        res = validate(123)
        # Assertion
        self.assertEqual(res, 'informational')

    def test_with_code_199(self):
        # Method Invocation
        res = validate(199)
        # Assertion
        self.assertEqual(res, 'informational')

    # Successful Responses
    def test_with_code_200(self):
        # Method Invocation
        res = validate(200)
        # Assertion
        self.assertEqual(res, 'successful')

    def test_with_code_2xx(self):
        # Method Invocation
        res = validate(234)
        # Assertion
        self.assertEqual(res, 'successful')
                
    def test_with_code_299(self):
        # Method Invocation
        res = validate(299)
        # Assertion
        self.assertEqual(res, 'successful')

    # Redirection Errors
    def test_with_code_300(self):
        # Method Invocation
        res = validate(300)
        # Assertion
        self.assertEqual(res, 'redirection')
                
    def test_with_code_3xx(self):
        # Method Invocation
        res = validate(345)
        # Assertion
        self.assertEqual(res, 'redirection')
    
    def test_with_code_399(self):
        # Method Invocation
        res = validate(399)
        # Assertion
        self.assertEqual(res, 'redirection')
    
    # Client Errors
    def test_with_code_400(self):
        # Method Invocation
        res = validate(400)
        # Assertion
        self.assertEqual(res, 'client error')

    def test_with_code_4xx(self):
        # Method Invocation
        res = validate(456)
        # Assertion
        self.assertEqual(res, 'client error')
                
    def test_with_code_499(self):
        # Method Invocation
        res = validate(499)
        # Assertion
        self.assertEqual(res, 'client error')

    # Server Errors
    def test_with_code_500(self):
        # Method Invocation
        res = validate(500)
        # Assertion
        self.assertEqual(res, 'server error')

    def test_with_code_5xx(self):
        # Method Invocation
        res = validate(567)
        # Assertion
        self.assertEqual(res, 'server error')
                
    def test_with_code_599(self):
        # Method Invocation
        res = validate(599)
        # Assertion
        self.assertEqual(res, 'server error')

    # Beyond valid range
    def test_with_code_600(self):
        # Method Invocation
        res = validate(600)
        # Assertion
        self.assertIsNone(res)

    def test_with_code_beyond_1000(self):
        # Method Invocation
        res = validate(1001)
        # Assertion
        self.assertIsNone(res)


if __name__ == '__main__':
    unittest.main()