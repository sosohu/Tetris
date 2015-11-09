#include "frame.h"
#include "log.h"
#include <algorithm>
#include <climits>

Log *pLog = Log::getLogInstance();

void SquareFrame::setFrameColor(const Color &edge, const Color &square, const Color &background) {
	m_edge_color = edge;
	m_square_color = square;
	m_color = background;
}

void SquareFrame::computeWidths(){
	for(size_t i = 0; i < m_height; i++){
		m_line_widths[i] = 0;
		for(size_t j = 0; j < m_width; j++){
			if(isSetBit(m_data_ptr, i + j * m_height))
				++m_line_widths[i];
		}
	}
}

void SquareFrame::computeHeights(){
	for(size_t j = 0; j < m_width; j++){
		m_col_heights[j] = 0;
		for(size_t i = 0; i < m_height; i++){
			if(isSetBit(m_data_ptr, i+ j * m_height)){
				m_col_heights[j] = m_height - i;
				break;
			}
		}
		pLog->Print(DEBUG, "m_col_heights[%d]: %d", j, m_col_heights[j]);
	}
}

void SquareFrame::clearLine(const Brick &follow_brick, size_t follow_i, size_t follow_j){
	pLog->Print(DEBUG, "follow_i: %d, follow_j: %d", follow_i, follow_j);
	int high = INT_MIN;
	int low = INT_MAX;
	for(size_t i = 0; i < 4; i++){
		for(size_t j = 0; j < 4; j++){
			if(follow_brick.isSet(i, j)){
				//++m_col_heights[follow_j + j];
				++m_line_widths[follow_i + i];
				if(m_line_widths[follow_i + i] == m_width){
					high = std::max(high, static_cast<int>(follow_i + i));
					low = std::min(low, static_cast<int>(follow_i + i));
				}
			}
		}
	}
	computeHeights();
	if(high != INT_MIN){
		pLog->Print(DEBUG, "high: %d, low: %d", high, low);
		for(size_t j = 0; j < m_width; j++){
			rightShiftBit(m_data_ptr, j * m_height, j * m_height + low - 1, high - low + 1);
			m_col_heights[j] = m_col_heights[j] - (high - low + 1);
			pLog->Print(DEBUG, "%d, %d, %d", j*m_height, j*m_height + low - 1, high - low + 1);
		}
		computeWidths();
	}
}

bool SquareFrame::isOver() const{
	for(size_t j = 0; j < m_width; j++){
		if(m_col_heights[j] >= m_height - 1)	return true;
	}
	return false;
}

void BodyFrame::setBodyFrameColor(const Color &c) {
	m_color = c;
}

void BodyFrame::setSquareFrameColor(const Color &edge, const Color &square, const Color &background) {
	m_square.setFrameColor(edge, square, background);
}

void BodyFrame::computeLife(){
	pLog->Print(DEBUG, "computeLife exec");
	m_follow_life = m_square.m_height;
	pLog->Print(DEBUG, "m_follow_life: %d", m_follow_life);
	for(size_t j = 0; j < 4; j++){
		size_t h = m_follow_i + (m_follow_brick.getLineHeight(j));
		pLog->Print(DEBUG, "h: %d", h);
		m_follow_life = std::min(m_follow_life, m_square.m_height - h - m_square.m_col_heights[m_follow_j + j]);
		pLog->Print(DEBUG, "m_follow_life: %d", m_follow_life);
	}
}

void BodyFrame::clear() {
	m_square.clearLine(m_follow_brick, m_follow_i, m_follow_j);
	if(m_square.isOver())	m_status = OVER;
	else	m_status = NEXT;
}

void BodyFrame::eliminate() {
	pLog->Print(DEBUG, "eliminate");
	for(size_t i = 0; i < 4; i++){
		for(size_t j = 0; j < 4; j++){
			if(m_follow_brick.isSet(i, j)){
				m_square.setData(m_follow_i + i, m_follow_j + j);
			}
		}
	}
}

void BodyFrame::uneliminate() {
	for(size_t i = 0; i < 4; i++){
		for(size_t j = 0; j < 4; j++){
			if(m_follow_brick.isSet(i, j)){
				m_square.unSetData(m_follow_i + i, m_follow_j + j);
			}
		}
	}
}

void BodyFrame::update() {
	switch (m_status) {
		case NEXT:	{
			pLog->Print(DEBUG, "Status NEXT");
			m_follow_brick = m_next_brick;
			m_next_brick = genRandBrick();
			m_follow_i = 0; // line
			m_follow_j = m_square.m_width / 2; // col
		}
		case START: {
			pLog->Print(DEBUG, "Status START");
			computeLife();
			m_status = FOLLOW;
		} break;
		case FOLLOW: {
			pLog->Print(DEBUG, "Status FOLLOW");
			uneliminate();
			++m_follow_i;
			--m_follow_life;
			if(!m_follow_life){
				m_status = MERGE;
			}
		} break;
		case MERGE: {
			pLog->Print(DEBUG, "Status MERGE");
			clear();
			return;
		} break;
		case OVER: {
			pLog->Print(DEBUG, "Status OVER");
			return;
		}
		default: ;
	}
	eliminate();
	//m_square.printData();
}

void BodyFrame::leftShift(size_t n){
	uneliminate();
	if(m_follow_j >= n){
		m_follow_j -= n;
	}else{
		 m_follow_j = 0;
	}
	computeLife();
	eliminate();
}

void BodyFrame::rightShift(size_t n){
	uneliminate();
	if(m_follow_j + n + m_follow_brick.getWidth() <= m_square.m_width){
		m_follow_j += n;
	}else{
		m_follow_j = m_square.m_width - m_follow_brick.getWidth();
	}
	computeLife();
	eliminate();
}

void BodyFrame::downShift(size_t n){
	if(m_status == FOLLOW){
		uneliminate();
		++m_follow_i;
		--m_follow_life;
		if(!m_follow_life){
			m_status = MERGE;
		}
		eliminate();
	}
}

void BodyFrame::changeFollow(){
	uneliminate();
	m_follow_brick.rorate();
	computeLife();
	eliminate();
}

void BodyFrame::pressUpdate() {
	
}
