##### Tokens #####

TT_INT   = "TT_INT"
TT_FLOAT = "FLOAT"
TT_ADD = "ADD"
TT_REMOVE
TT_PUSH
TT_MULT

class Token:
    def __init__(sel, type_, value):
        self.type = type_,
        self.value = value

    def __repr__(self):
        if self.value: return f'{self.type}:{self.value}'
        return f'{self.type}'