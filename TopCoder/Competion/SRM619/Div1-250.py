class SplitStoneGame:
    def winOrLose(self, number):
        if max(number) == 1 or len(number) < 3 or len(number) % 2 == 0:
            return 'LOSE'
        return 'WIN'