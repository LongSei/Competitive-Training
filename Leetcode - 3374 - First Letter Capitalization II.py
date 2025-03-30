import pandas as pd

def capitalize_content(user_content: pd.DataFrame) -> pd.DataFrame:
    text_list = list(user_content['content_text'])
    text_list_sep_by_space_split_space = list(map((lambda string : string.split(" ")), text_list))
    text_list_sep_by_space_process = list(
        map(
            lambda list_word : 
                " ".join(
                    list(map(
                        lambda word : 
                        "-".join([_.lower().capitalize() for _ in word.split('-')]) if '-' in word else word.lower().capitalize(), 
                        list_word)
                    )
                ), 
                text_list_sep_by_space_split_space
        )
    )
    user_content = user_content.rename(columns={'content_text':'original_text'})
    user_content['converted_text'] = text_list_sep_by_space_process
    return user_content
