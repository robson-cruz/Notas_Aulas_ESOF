from social_media import account

anna_user = account.InstagramAccount("Anna", 4500, 16)

print(f"Anna Instagram\n"
      f"User Name: {anna_user.username}\n"
      f"Followers: {anna_user.n_followers}\n"
      f"Folowing: {anna_user.n_following}")
