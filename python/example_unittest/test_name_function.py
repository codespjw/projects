# test_name_function.py
import unittest
from name_functions import get_formatted_name


class NameTestCase(unittest.TestCase):
    """测试name_function.py"""

    def test_first_last_name(self):
        """能处理如Janis Joplin 这样的姓名吗？"""
        formatted_name = get_formatted_name('janis', 'joplin')
        self.assertEqual(formatted_name, 'Janis Joplin')

    def test_middle(self):  # 添加新方法用以处理如Tom Li Jerry 这样的名字
        """能处理如Tom Li Jerry 这样的名字？"""
        formatted_name = get_formatted_name('tom', 'jerry', 'li')
        self.assertEqual(formatted_name, 'Tom Li Jerry')


unittest.main()
