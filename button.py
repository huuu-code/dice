import pygame


def draw_button ( window, x, y, width, height, bg_color, title, text_color=(100, 100, 100), font_size=32 ):
	pygame.draw.rect ( window, bg_color, (x, y, width, height) )
	font = pygame.font.Font ( '素材/字体1.ttf', font_size )
	text = font.render ( title, True, text_color )
	t_w, t_h = text.get_size ( )
	window.blit ( text, (x + width / 2 - t_w / 2, y + height / 2 - t_h / 2) )


# 定义一个Button类
class Button:
	# 传入按钮文字，坐标，大小，背景颜色，文字颜色，默认文字大小32
	def __init__ ( self, title, pos, size, bg_color, text_color, font_size=32 ):
		self.title = title
		self.pos = pos
		self.size = size
		self.bg_color = bg_color
		self.text_color = text_color
		self.font_size = font_size
		self.old_color = bg_color

	# 画按钮
	def draw1 ( self, window ):
		self.rect = pygame.Rect ( self.pos [ 0 ], self.pos [ 1 ], self.size [ 0 ], self.size [ 1 ] )
		pygame.draw.rect ( window, self.bg_color, self.rect )
		self.font = pygame.font.Font ( '素材/字体1.ttf', self.font_size )
		text = self.font.render ( self.title, True, self.text_color )
		t_w, t_h = text.get_size ( )
		window.blit ( text,(self.pos [ 0 ] + self.size [ 0 ] / 2 - t_w / 2, self.pos [ 1 ] + self.size [ 1 ] / 2 - t_h / 2) )

	# 当鼠标按下
	def is_down ( self, pos, window ):
		m_x, m_y = pos
		btn_x, btn_y = self.pos
		btn_w, btn_h = self.size
		if btn_x <= m_x <= btn_x + btn_w and btn_y <= m_y <= btn_y + btn_h: # 判断鼠标位置是否在按钮范围内
			self.bg_color = (200, 200, 200)
			self.draw1 ( window )
			pygame.display.update ( )
			return True
		else:
			return False
		#return True

	# 当鼠标弹起
	def is_up ( self, pos, window ):
		m_x, m_y = pos
		btn_x, btn_y = self.pos
		btn_w, btn_h = self.size
		if btn_x <= m_x <= btn_x + btn_w and btn_y <= m_y <= btn_y + btn_h: # 判断鼠标位置是否在按钮范围内
			self.bg_color = self.old_color
			self.draw1 ( window )
			pygame.display.update ( )
			return True
		else:
			return False
		#return True
