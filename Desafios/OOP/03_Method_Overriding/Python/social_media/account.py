class Account:
    """The creation of the Account class and its relative functionality"""

    def __init__(self, media, username, n_followers):
        """The initializer for the class Account

        Arguments:
            media -- a string representing the user
            username -- a string representing the user's name
            n_followers -- an int representing the number of users that are following the user
        """
        self.media = media
        self.username = username
        self.n_followers = n_followers
        print("Account Created")


class InstagramAccount(Account):
    """The creation of the InstagramAccount class and its relative functionality"""

    def __init__(self, username, n_followers, n_following):
        """The initializer for the class InstagramAccount

        Arguments:
            username -- a string inherited from Account class representing the user's name
            n_followers -- an int inherited from Account class representing the number of followers
            n_following -- an int representing the users that the user is following
        """
        super().__init__("Instagram", username, n_followers)  # Media is fixed to "Instagram"
        self.n_following = n_following
