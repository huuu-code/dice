import pygame
from button import Button
from 博饼 import res,check_result


width1 = 360  # 窗口宽度
height1 = 750  # 窗口高度


pygame.init ( )
# 初始化界面
window = pygame.display.set_mode ( (width1, height1) )
pygame.display.set_caption ( '中秋融情月意之博饼' )
window.fill ( (255, 255, 255) )


# 背景音乐设置
def music():
	pygame.mixer.init()
	pygame.mixer.music.load('素材/bg_music.wav')
	pygame.mixer.music.play ( -1 )
	voice = 0.5
	pygame.mixer.music.set_volume ( voice)


#规则奖励页面
def rule_bg():
	image1 = pygame.image.load ( '素材/规则奖励.jpg' )
	window.blit ( image1, (0, 50) )
	# 创建字体对象
	font = pygame.font.Font ( '素材/字体1.ttf', 24 )  # Font(字体文字路径，字号)
	# 创建文字对象
	text = font.render ( '您好，欢迎，祝您游戏愉快！', True, (255, 0, 0), (100, 0, 0) )
	window.blit ( text, (20, 0) )



# 显示输入游戏人数
# def show_number():
# 	font =  pygame.font.Font ( '素材/字体1.ttf', 24 )  # Font(字体文字路径，字号)
# 	text = f"选择游戏人数: {num()}"
# 	num_render =	font.render ( text, True, (255, 0, 0), (100, 0, 0) )
# 	window.blit ( num_render, (100, 70) )
# 	return True



# 背景设置
def bg_game ( ):
	image1 = pygame.image.load ( '素材/图1.jpg' )
	window.blit ( image1, (0, 50) )
	# 创建字体对象
	font = pygame.font.Font ( '素材/字体1.ttf', 24 )  # Font(字体文字路径，字号)
	# 创建文字对象
	text = font.render ( '您好，欢迎，祝您游戏愉快！', True, (255, 0, 0), (100, 0, 0) )
	window.blit ( text, (20, 0) )



#显示游戏结果
def show_result():
	font =  pygame.font.Font ( '素材/字体1.ttf', 24 )  # Font(字体文字路径，字号)
	check_result().clear()
	text1 = f"您的游戏结果为:"
	text2 = f"{res()}"
	result1_render =	font.render ( text1, True, (255, 0, 0), (100, 0, 0) )
	result2_render = font.render ( text2, True, (255, 0, 0), (100, 0, 0) )
	window.blit ( result1_render, (90, 100) )
	window.blit(result2_render, (75, 220))


# 定义各个按钮
button1 = Button ( '开始游戏', (110, 150), (150, 50), (255, 0, 0), (255, 255, 255) )
button2 = Button ( '游戏规则', (110, 250), (150, 50), (255, 0, 0), (255, 255, 255) )
button3 = Button ( '退出游戏', (110, 350), (150, 50), (255, 0, 0), (255, 255, 255) )
button4 = Button ( '奖品一览', (110, 450), (150, 50), (255, 0, 0), (255, 255, 255) )
button5 = Button ( '请玩家摇骰子', (85, 600), (200, 50), (255, 0, 0), (255, 255, 255) )
button6 = Button ( '结束游戏', (110, 680), (150, 50), (255, 0, 0), (255, 255, 255) )
button7 = Button ( '返回', (210, 250), (150, 30), (0, 200, 0), (255, 255, 255) )
# 显示主页
bg_game ( )
button1.draw1 ( window )
button2.draw1 ( window )
button3.draw1 ( window )
button4.draw1 ( window )
# #开始游戏跳转
# def tz1():
# 	global button1,button5
# 	running = True
# 	while running:
# 		for event in pygame.event.get ( ):
# 			if event.type == pygame.QUIT:
# 				exit ( )
# 			if event.type == pygame.MOUSEBUTTONDOWN:
# 				if button1.is_down ( event.pos, window ):
# 					pass
# 			if event.type == pygame.MOUSEBUTTONUP:
# 				if button1.is_up ( event.pos, window ):
# 					bg_game ( )
# 					button5.draw1 ( window )
# 					running = False
# 					pygame.display.update ( )
#
#
#
# #结果跳转
# def tz2():
# 	global button6, button5
# 	running = True
# 	while running:
# 		for event in pygame.event.get ( ):
# 			if event.type == pygame.QUIT:
# 				exit ( )
# 			if event.type == pygame.MOUSEBUTTONDOWN:
# 				if button5.is_down ( event.pos, window ):
# 					pass
# 			if event.type == pygame.MOUSEBUTTONUP:
# 				if button5.is_up ( event.pos, window ):
# 					bg_game ( )
# 					button6.draw1 ( window )
# 					running = False
# 					pygame.display.update ( )
#
#
# #结束页面跳转回主页
# def tz3():
# 	global button6, button5,button4, button3, button2, button1
# 	running = True
# 	while running:
# 		for event in pygame.event.get ( ):
# 			if event.type == pygame.QUIT:
# 				exit ( )
# 			if event.type == pygame.MOUSEBUTTONDOWN:
# 				if button6.is_down ( event.pos, window ):
# 					pass
# 			if event.type == pygame.MOUSEBUTTONUP:
# 				if button6.is_up ( event.pos, window ):
# 					bg_game ( )
# 					button1.draw1 ( window )
# 					button2.draw1 ( window )
# 					button3.draw1 ( window )
# 					button4.draw1 ( window )
# 					running = False
# 					pygame.display.update ( )
#
# #规则页面跳转
# def tz4():
# 	running = True
# 	while running:
# 		for event in pygame.event.get ( ):
# 			if event.type == pygame.MOUSEBUTTONDOWN:
# 				if button2.is_down ( event.pos, window ):
# 					pass
# 			if event.type == pygame.MOUSEBUTTONUP:
# 				if button2.is_up ( event.pos, window ):
# 					rule_bg ( )
# 					button7.draw1(window)
# 					running = False
# 					pygame.display.update()
#
#
# #规则页面跳转主页
# def tz5():
# 	running = True
# 	while running:
# 		for event in pygame.event.get ( ):
# 			if event.type == pygame.MOUSEBUTTONDOWN:
# 				if button7.is_down ( event.pos, window ):
# 					pass
# 			if event.type == pygame.MOUSEBUTTONUP:
# 				if button7.is_up ( event.pos, window ):
# 					bg_game ( )
# 					button1.draw1 ( window )
# 					button2.draw1 ( window )
# 					button3.draw1 ( window )
# 					button4.draw1 ( window )
# 					running = False
# 					pygame.display.update ( )



# 刷新主页
pygame.display.flip()
#播放音乐
music()
while True:
	for event in pygame.event.get ( ):
		# 主页跳转游戏页面
		if event.type == pygame.MOUSEBUTTONDOWN:
			if button1.is_down ( event.pos, window ):
				pass
		if event.type == pygame.MOUSEBUTTONUP:
			if button1.is_up ( event.pos, window ):
				bg_game ( )
				button5.draw1 ( window )
				#show_number()
				pygame.display.update ( )

		# 游戏页面跳转结束页面
		if event.type == pygame.MOUSEBUTTONDOWN:
			if button5.is_down ( event.pos, window ):
				pass
		if event.type == pygame.MOUSEBUTTONUP:
			if button5.is_up ( event.pos, window ):
				bg_game ( )
				button5.draw1 ( window )
				button6.draw1 ( window)
				show_result()
				pygame.display.update ( )


		# 结束页面跳转回主页
		if event.type == pygame.MOUSEBUTTONDOWN:
			if button6.is_down ( event.pos, window ):
				pass
		if event.type == pygame.MOUSEBUTTONUP:
			if button6.is_up ( event.pos, window ):
				bg_game ( )
				button1.draw1 ( window )
				button2.draw1 ( window )
				button3.draw1 ( window )
				button4.draw1 ( window )
				pygame.display.update ( )

		# 跳转规则奖励页面
		if event.type == pygame.MOUSEBUTTONDOWN:
			if button2.is_down ( event.pos, window ) or button4.is_down ( event.pos, window ) :
				pass
		if event.type == pygame.MOUSEBUTTONUP:
			if button2.is_up ( event.pos, window ) or button4.is_up ( event.pos, window ):
				rule_bg ( )
				button7.draw1 ( window )
				pygame.display.update ( )
		# 规则页面跳转主页
		if event.type == pygame.MOUSEBUTTONDOWN:
			if button7.is_down ( event.pos, window ):
				pass
		if event.type == pygame.MOUSEBUTTONUP:
			if button7.is_up ( event.pos, window ):
				bg_game ( )
				button1.draw1 ( window )
				button2.draw1 ( window )
				button3.draw1 ( window )
				button4.draw1 ( window )
				running = False
				pygame.display.update ( )


		# 退出游戏
		if event.type == pygame.MOUSEBUTTONDOWN:
			if button3.is_down ( event.pos, window ):
				pass
		if event.type == pygame.MOUSEBUTTONUP:
			if button3.is_up ( event.pos, window ):
				pygame.quit()

		if event.type == pygame.QUIT:
			pygame.quit()
			exit()