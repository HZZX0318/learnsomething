class Exchange:
    # implement this!
    trades=[]
    def __init__(self, initialBalance):
        self.balance = initialBalance
        return None

    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """
        self.trade = trade
        trades.append(trade)

