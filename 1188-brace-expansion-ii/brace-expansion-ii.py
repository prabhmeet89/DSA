class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        pos = 0
        n = len(expression)

        def parseExpr():
            nonlocal pos
            result = parseTerm()
            while pos < n and expression[pos] == ',':
                pos += 1
                result |= parseTerm()
            return result

        def parseTerm():
            nonlocal pos
            result = {""}
            while pos < n and expression[pos] not in ',}':
                factor = parseFactor()
                result = {a + b for a in result for b in factor}
            return result

        def parseFactor():
            nonlocal pos
            if expression[pos] == '{':
                pos += 1                 # skip '{'
                s = parseExpr()
                pos += 1                 # skip '}'
                return s
            else:
                start = pos
                while pos < n and expression[pos].isalpha():
                    pos += 1
                return {expression[start:pos]}

        return sorted(parseExpr())